# Load the base timestamp/event fields (slurpfile = array of files)
$base[0] as $b |

# Ensure .properties exists
(.properties // {}) as $props |

# Add timestamp/event into .properties
.properties = ($b + $props) |

# Ensure .required exists and add fields
.required = (["timestamp", "event"] + (.required // []) | unique) |

# Remove unsupported inheritance keys
del(.allOf, .extends)