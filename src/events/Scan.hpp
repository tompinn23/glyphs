//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     scan data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct atmospheric_composition {
        std::string name;
        double percent;
    };

    /**
     * Written for Planet/Moon
     */
    struct composition_entry {
        double ice;
        double metal;
        double rock;
    };

    struct scan_material {
        std::string name;
        std::optional<std::string> name_localised;
        double percent;
    };

    struct parent {
        std::optional<int64_t> null;
        std::optional<int64_t> planet;
        std::optional<int64_t> ring;
        std::optional<int64_t> star;
    };

    struct ring {
        double inner_rad;
        /**
         * In megatons
         */
        double mass_mt;
        std::string name;
        double outer_rad;
        std::string ring_class;
    };

    /**
     * When Written: basic or detailed discovery scan of a star, planet or moon. This is also
     * generated when scanning a navigation beacon in a populated system, to record info about
     * all the bodies in the system.
     */
    struct scan {
        /**
         * Written for Star
         */
        std::optional<double> absolute_magnitude;
        /**
         * Written for Star
         */
        std::optional<int64_t> age_my;
        /**
         * Written for Star/Planet/Moon
         */
        std::optional<double> ascending_node;
        /**
         * Written for Planet/Moon
         */
        std::optional<std::string> atmosphere;
        /**
         * Written for Planet/Moon
         */
        std::optional<std::vector<atmospheric_composition>> atmosphere_composition;
        /**
         * Written for Planet/Moon
         */
        std::optional<std::string> atmosphere_type;
        /**
         * If rotating. Written for Star/Planet/Moon
         */
        std::optional<double> axial_tilt;
        /**
         * Written for Star/Planet/Moon
         */
        int64_t body_id;
        /**
         * Written for Star/Planet/Moon
         */
        std::string body_name;
        /**
         * Written for Planet/Moon
         */
        std::optional<composition_entry> composition;
        /**
         * Written for Star/Planet/Moon
         */
        double distance_from_arrival_ls;
        /**
         * Orbital Parameters for any Star/Planet/Moon (except main star of single-star system)
         */
        std::optional<double> eccentricity;
        std::string event;
        /**
         * Written for Planet/Moon
         */
        std::optional<bool> landable;
        /**
         * Written for Star
         */
        std::optional<std::string> luminosity;
        /**
         * Body mass. Written for Planet/Moon
         */
        std::optional<double> mass_em;
        /**
         * Written for Planet/Moon
         */
        std::optional<std::vector<scan_material>> materials;
        /**
         * Written for Star/Planet/Moon
         */
        std::optional<double> mean_anomaly;
        /**
         * Orbital Parameters for any Star/Planet/Moon (except main star of single-star system)
         */
        std::optional<double> orbital_inclination;
        /**
         * Orbital Parameters for any Star/Planet/Moon (except main star of single-star system)
         */
        std::optional<double> orbital_period;
        /**
         * Written for Star/Planet/Moon
         */
        std::optional<std::vector<parent>> parents;
        /**
         * Orbital Parameters for any Star/Planet/Moon (except main star of single-star system)
         */
        std::optional<double> periapsis;
        /**
         * Written for Planet/Moon
         */
        std::optional<std::string> planet_class;
        /**
         * Written for Star
         */
        std::optional<double> radius;
        /**
         * Written for Planet/Moon. If rings present.
         */
        std::optional<std::string> reserve_level;
        /**
         * Written for Star/Planet/Moon. If rings present.
         */
        std::optional<std::vector<ring>> rings;
        /**
         * Written for Star/Planet/Moon. If rotating (in seconds)
         */
        std::optional<double> rotation_period;
        /**
         * Written for Star/Planet/Moon
         */
        std::string scan_type;
        /**
         * Orbital Parameters for any Star/Planet/Moon (except main star of single-star system)
         */
        std::optional<double> semi_major_axis;
        /**
         * Written for Star
         */
        std::string star_system;
        /**
         * Written for Star
         */
        std::optional<std::string> star_type;
        /**
         * Written for Star
         */
        std::optional<double> stellar_mass;
        /**
         * Written for Star
         */
        std::optional<int64_t> subclass;
        /**
         * Written for Planet/Moon
         */
        std::optional<double> surface_gravity;
        /**
         * Written for Planet/Moon
         */
        std::optional<double> surface_pressure;
        /**
         * Written for Star/Planet/Moon
         */
        std::optional<double> surface_temperature;
        /**
         * Written for Star
         */
        int64_t system_address;
        /**
         * Written for Planet/Moon
         */
        std::optional<std::string> terraform_state;
        /**
         * Written for Planet/Moon
         */
        std::optional<bool> tidal_lock;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        /**
         * Written for Planet/Moon
         */
        std::optional<std::string> volcanism;
        /**
         * Written for Star/Planet/Moon
         */
        bool was_discovered;
        std::optional<bool> was_footfalled;
        /**
         * Written for Star/Planet/Moon
         */
        bool was_mapped;
    };
}

namespace hue {
    void from_json(const json & j, atmospheric_composition & x);
    void to_json(json & j, const atmospheric_composition & x);

    void from_json(const json & j, composition_entry & x);
    void to_json(json & j, const composition_entry & x);

    void from_json(const json & j, scan_material& x);
    void to_json(json & j, const scan_material& x);

    void from_json(const json & j, parent & x);
    void to_json(json & j, const parent & x);

    void from_json(const json & j, ring & x);
    void to_json(json & j, const ring & x);

    void from_json(const json & j, scan & x);
    void to_json(json & j, const scan & x);

    inline void from_json(const json & j, atmospheric_composition& x) {
        x.name = j.at("Name").get<std::string>();
        x.percent = j.at("Percent").get<double>();
    }

    inline void to_json(json & j, const atmospheric_composition & x) {
        j = json::object();
        j["Name"] = x.name;
        j["Percent"] = x.percent;
    }

    inline void from_json(const json & j, composition_entry& x) {
        x.ice = j.at("Ice").get<double>();
        x.metal = j.at("Metal").get<double>();
        x.rock = j.at("Rock").get<double>();
    }

    inline void to_json(json & j, const composition_entry & x) {
        j = json::object();
        j["Ice"] = x.ice;
        j["Metal"] = x.metal;
        j["Rock"] = x.rock;
    }

    inline void from_json(const json & j, scan_material& x) {
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.percent = j.at("Percent").get<double>();
    }

    inline void to_json(json & j, const scan_material& x) {
        j = json::object();
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["Percent"] = x.percent;
    }

    inline void from_json(const json & j, parent& x) {
        x.null = get_stack_optional<int64_t>(j, "Null");
        x.planet = get_stack_optional<int64_t>(j, "Planet");
        x.ring = get_stack_optional<int64_t>(j, "Ring");
        x.star = get_stack_optional<int64_t>(j, "Star");
    }

    inline void to_json(json & j, const parent & x) {
        j = json::object();
        j["Null"] = x.null;
        j["Planet"] = x.planet;
        j["Ring"] = x.ring;
        j["Star"] = x.star;
    }

    inline void from_json(const json & j, ring& x) {
        x.inner_rad = j.at("InnerRad").get<double>();
        x.mass_mt = j.at("MassMT").get<double>();
        x.name = j.at("Name").get<std::string>();
        x.outer_rad = j.at("OuterRad").get<double>();
        x.ring_class = j.at("RingClass").get<std::string>();
    }

    inline void to_json(json & j, const ring & x) {
        j = json::object();
        j["InnerRad"] = x.inner_rad;
        j["MassMT"] = x.mass_mt;
        j["Name"] = x.name;
        j["OuterRad"] = x.outer_rad;
        j["RingClass"] = x.ring_class;
    }

    inline void from_json(const json & j, scan& x) {
        x.absolute_magnitude = get_stack_optional<double>(j, "AbsoluteMagnitude");
        x.age_my = get_stack_optional<int64_t>(j, "Age_MY");
        x.ascending_node = get_stack_optional<double>(j, "AscendingNode");
        x.atmosphere = get_stack_optional<std::string>(j, "Atmosphere");
        x.atmosphere_composition = get_stack_optional<std::vector<atmospheric_composition>>(j, "AtmosphereComposition");
        x.atmosphere_type = get_stack_optional<std::string>(j, "AtmosphereType");
        x.axial_tilt = get_stack_optional<double>(j, "AxialTilt");
        x.body_id = j.at("BodyID").get<int64_t>();
        x.body_name = j.at("BodyName").get<std::string>();
        x.composition = get_stack_optional<composition_entry>(j, "Composition");
        x.distance_from_arrival_ls = j.at("DistanceFromArrivalLS").get<double>();
        x.eccentricity = get_stack_optional<double>(j, "Eccentricity");
        x.event = j.at("event").get<std::string>();
        x.landable = get_stack_optional<bool>(j, "Landable");
        x.luminosity = get_stack_optional<std::string>(j, "Luminosity");
        x.mass_em = get_stack_optional<double>(j, "MassEM");
        x.materials = get_stack_optional<std::vector<scan_material>>(j, "Materials");
        x.mean_anomaly = get_stack_optional<double>(j, "MeanAnomaly");
        x.orbital_inclination = get_stack_optional<double>(j, "OrbitalInclination");
        x.orbital_period = get_stack_optional<double>(j, "OrbitalPeriod");
        x.parents = get_stack_optional<std::vector<parent>>(j, "Parents");
        x.periapsis = get_stack_optional<double>(j, "Periapsis");
        x.planet_class = get_stack_optional<std::string>(j, "PlanetClass");
        x.radius = get_stack_optional<double>(j, "Radius");
        x.reserve_level = get_stack_optional<std::string>(j, "ReserveLevel");
        x.rings = get_stack_optional<std::vector<ring>>(j, "Rings");
        x.rotation_period = get_stack_optional<double>(j, "RotationPeriod");
        x.scan_type = j.at("ScanType").get<std::string>();
        x.semi_major_axis = get_stack_optional<double>(j, "SemiMajorAxis");
        x.star_system = j.at("StarSystem").get<std::string>();
        x.star_type = get_stack_optional<std::string>(j, "StarType");
        x.stellar_mass = get_stack_optional<double>(j, "StellarMass");
        x.subclass = get_stack_optional<int64_t>(j, "Subclass");
        x.surface_gravity = get_stack_optional<double>(j, "SurfaceGravity");
        x.surface_pressure = get_stack_optional<double>(j, "SurfacePressure");
        x.surface_temperature = get_stack_optional<double>(j, "SurfaceTemperature");
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.terraform_state = get_stack_optional<std::string>(j, "TerraformState");
        x.tidal_lock = get_stack_optional<bool>(j, "TidalLock");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.volcanism = get_stack_optional<std::string>(j, "Volcanism");
        x.was_discovered = j.at("WasDiscovered").get<bool>();
        x.was_footfalled = get_stack_optional<bool>(j, "WasFootfalled");
        x.was_mapped = j.at("WasMapped").get<bool>();
    }

    inline void to_json(json & j, const scan & x) {
        j = json::object();
        j["AbsoluteMagnitude"] = x.absolute_magnitude;
        j["Age_MY"] = x.age_my;
        j["AscendingNode"] = x.ascending_node;
        j["Atmosphere"] = x.atmosphere;
        j["AtmosphereComposition"] = x.atmosphere_composition;
        j["AtmosphereType"] = x.atmosphere_type;
        j["AxialTilt"] = x.axial_tilt;
        j["BodyID"] = x.body_id;
        j["BodyName"] = x.body_name;
        j["Composition"] = x.composition;
        j["DistanceFromArrivalLS"] = x.distance_from_arrival_ls;
        j["Eccentricity"] = x.eccentricity;
        j["event"] = x.event;
        j["Landable"] = x.landable;
        j["Luminosity"] = x.luminosity;
        j["MassEM"] = x.mass_em;
        j["Materials"] = x.materials;
        j["MeanAnomaly"] = x.mean_anomaly;
        j["OrbitalInclination"] = x.orbital_inclination;
        j["OrbitalPeriod"] = x.orbital_period;
        j["Parents"] = x.parents;
        j["Periapsis"] = x.periapsis;
        j["PlanetClass"] = x.planet_class;
        j["Radius"] = x.radius;
        j["ReserveLevel"] = x.reserve_level;
        j["Rings"] = x.rings;
        j["RotationPeriod"] = x.rotation_period;
        j["ScanType"] = x.scan_type;
        j["SemiMajorAxis"] = x.semi_major_axis;
        j["StarSystem"] = x.star_system;
        j["StarType"] = x.star_type;
        j["StellarMass"] = x.stellar_mass;
        j["Subclass"] = x.subclass;
        j["SurfaceGravity"] = x.surface_gravity;
        j["SurfacePressure"] = x.surface_pressure;
        j["SurfaceTemperature"] = x.surface_temperature;
        j["SystemAddress"] = x.system_address;
        j["TerraformState"] = x.terraform_state;
        j["TidalLock"] = x.tidal_lock;
        j["timestamp"] = x.timestamp;
        j["Volcanism"] = x.volcanism;
        j["WasDiscovered"] = x.was_discovered;
        j["WasFootfalled"] = x.was_footfalled;
        j["WasMapped"] = x.was_mapped;
    }
}


