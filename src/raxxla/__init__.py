from __future__ import annotations

from collections.abc import Generator, AsyncGenerator
from typing import TYPE_CHECKING, Any, Union

import anyio

from ._core import (
    BackpackContents,
    FuelTanks,
    Module,
    ModuleEngineering,
    ModuleModifier,
    PowerplayInfo,
    Reader,
    State,
    Suit,
    SuitLoadout,
)

__all__ = [
    "BackpackContents",
    "FuelTanks",
    "Module",
    "ModuleEngineering",
    "ModuleModifier",
    "PowerplayInfo",
    "Reader",
    "State",
    "Suit",
    "SuitLoadout",
]

if TYPE_CHECKING:
    import asyncio
    from typing import Protocol

    import trio

    AnyEvent = Union[anyio.Event, asyncio.Event, trio.Event]

    class AbstractEvent(Protocol):
        def is_set(self) -> bool: ...


def read(
    journal_dir: str, timeout: int = 0, stop_event: AnyEvent | None = None
) -> Generator[tuple[State, dict[str, Any]]]:
    with Reader(journal_dir) as reader:
        for ev in reader.events(timeout, stop_event):
            if isinstance(ev, str):
                if ev == 'stop':
                    break
                if ev == 'timeout':
                    print("timeout")
                    break
            else:
                yield ev

async def aread(journal_dir: str, timeout: int | None = None, stop_event: AnyEvent | None = None) -> AsyncGenerator[tuple[State, dict[str, Any]]]:
    if stop_event is None:
        stop_event_: AnyEvent = anyio.Event()
    else:
        stop_event_ = stop_event
    
    timeout = timeout or 1_000
    CancelledError = anyio.get_cancelled_exc_class()

    with Reader(journal_dir) as reader:
        while True:
            try:
                raw = await anyio.to_thread_run_sync(reader.events, timeout, stop_event_)
            except (CancelledError, KeyboardInterrupt):
                stop_event_.set()
                raise

            if raw == "stop":
                return
            elif raw == "timeout":
                continue
            elif isinstance(raw, tuple):
                yield raw
            else:
                raise RuntimeError(f"Unexpected event: {raw!r}")

