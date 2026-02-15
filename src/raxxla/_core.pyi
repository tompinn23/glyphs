from dataclasses import dataclass
from typing import Dict, List, Tuple, Union, Set, Iterator, Any

@dataclass(frozen=True)
class ModuleModifier:
    label: str
    less_is_good: int | None
    original_value: float | None
    value: float | None
    value_str: str | None
    value_str_localised: str | None


@dataclass(frozen=True)
class ModuleEngineering:
    blueprint_id: int
    blueprint_name: str
    engineer: str | None
    engineer_id: int
    experimental_effect: str | None
    experimental_effect_localised: str | None
    level: int
    modifiers: List[ModuleModifier]
    quality: float


@dataclass(frozen=True)
class FuelTanks:
    main: float
    reserve: float


@dataclass(frozen=True)
class Module:
    ammo_in_clip: int | None
    ammo_in_hopper: int | None
    engineering: ModuleEngineering | None
    health: float
    item: str
    on: bool
    priority: int
    slot: str
    value: int | None


@dataclass(frozen=True)
class Suit:
    suit_id: int
    edmc_name: str
    loc_name: str
    name: str
    mods: List[str]
    id: int | None


@dataclass(frozen=True)
class SuitLoadout:
    loadout_slot_id: int
    suit: Suit
    name: str
    slots: Dict[str, str]


@dataclass(frozen=True)
class BackpackContents:
    component: Dict[str, int]
    consumable: Dict[str, int]
    item: Dict[str, int]
    data: Dict[str, int]


@dataclass(frozen=True)
class PowerplayInfo:
    power: str | None
    rank: int | None
    merits: int | None
    votes: int | None
    time_pledged: int | None


@dataclass(frozen=True)
class State:
    game_language: str | None
    game_version: str | None
    game_build: str | None

    captain: str | None
    cargo: Dict[str, int]
    credits: int
    fid: str | None
    horizons: bool | None
    odyssey: bool
    loan: int | None

    raw: Dict[str, int]
    manufactured: Dict[str, int]
    encoded: Dict[str, int]

    engineers: Dict[str, Union[Tuple[int, int], str]]
    rank: Dict[str, Tuple[int, int]]
    reputation: Dict[str, int]
    statistics: Dict[str, int]

    role: str | None

    friends: Set[str]

    ship_id: int | None
    ship_ident: str | None
    ship_name: str | None
    ship_type: str | None
    hull_value: int | None
    modules_value: int | None
    unladen_mass: float | None
    cargo_capacity: int | None
    max_jump_range: float | None
    fuel_capacity: FuelTanks | None
    rebuy: int | None

    modules: Dict[str, Module]
    cargo_json: str | None
    route: str | None

    is_docked: bool
    on_foot: bool

    component: Dict[str, int]
    item: Dict[str, int]
    consumable: Dict[str, int]
    data: Dict[str, int]

    backpack: BackpackContents
    backpack_json: str | None
    ship_locker_json: str | None

    suits: Dict[int, Suit]
    suit_loadouts: Dict[int, SuitLoadout]
    suit_current: int | None
    suit_loadout_current: int | None

    taxi: bool
    dropship: bool

    star_pos: List[float]
    system_address: int | None
    system_name: str | None
    system_population: int | None
    body: str | None
    body_id: int | None
    body_type: str | None
    station_name: str | None
    station_type: str | None
    market_id: int | None

    nav_route: str | None

    power_play: PowerplayInfo

class Reader:
    def __init__(self, journal_dir: str) -> None: ...

    def events(self, max_timeout: int, stop_event: Any) -> Iterator[Union[str, tuple[State, dict[str, Any]]]]: ...

    def __enter__(self) -> Reader: ...

    def __exit__(self, exc_type: type | None, exc_value: BaseException | None, traceback: Any | None) -> None: ...