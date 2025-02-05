#pragma once

#include "entities_chars.hpp"
#include "screen.hpp"
#include "state.hpp"

#include <cstdint>
#include <functional>
#include <vector>

void teleport(float x, float y, bool s, float vx, float vy, bool snap);
void godmode(bool g);
void darkmode(bool g);
void zoom(float level);
void attach_entity(Entity* overlay, Entity* attachee);
void attach_entity_by_uid(uint32_t overlay_uid, uint32_t attachee_uid);
int32_t attach_ball_and_chain(uint32_t uid, float off_x, float off_y);
void stack_entities(uint32_t bottom_uid, uint32_t top_uid, float (&offset)[2]);
int32_t get_entity_at(float x, float y, bool s, float radius, uint32_t mask);
int32_t get_grid_entity_at(float x, float y, LAYER layer);
void move_entity(uint32_t uid, float x, float y, bool s, float vx, float vy, bool snap);
void move_entity_abs(uint32_t uid, float x, float y, float vx, float vy);
uint32_t get_entity_flags(uint32_t uid);
void set_entity_flags(uint32_t uid, uint32_t flags);
uint32_t get_entity_flags2(uint32_t id);
void set_entity_flags2(uint32_t uid, uint32_t flags);
void set_hud_flags(uint32_t flags);
uint32_t get_hud_flags();
void set_pause(uint8_t pause);
void player_status();
Screen* get_screen_ptr(uint32_t screen_id);
Entity* get_entity_ptr(uint32_t uid);
ENT_TYPE get_entity_type(uint32_t uid);
int get_entity_ai_state(uint32_t uid);
StateMemory* get_state_ptr();
std::vector<Player*> get_players();
std::pair<float, float> click_position(float x, float y);
std::pair<float, float> screen_position(float x, float y);
std::tuple<float, float, float, float> screen_aabb(float x1, float y1, float x2, float y2);
float screen_distance(float x);
float get_zoom_level();
std::vector<uint32_t> filter_entities(std::vector<uint32_t> entities, std::function<bool(Entity*)> predicate);
std::vector<uint32_t> get_entities();
std::vector<uint32_t> get_entities_by(std::vector<ENT_TYPE> entity_types, uint32_t mask, LAYER layer);
std::vector<uint32_t> get_entities_by(ENT_TYPE entity_type, uint32_t mask, LAYER layer);
std::vector<uint32_t> get_entities_by_type(std::vector<ENT_TYPE> entity_types);
std::vector<uint32_t> get_entities_by_type(ENT_TYPE entity_type);
std::vector<uint32_t> get_entities_by_mask(uint32_t mask);
std::vector<uint32_t> get_entities_by_layer(LAYER layer);
std::vector<uint32_t> get_entities_at(std::vector<ENT_TYPE> entity_types, uint32_t mask, float x, float y, LAYER layer, float radius);
std::vector<uint32_t> get_entities_at(ENT_TYPE entity_type, uint32_t mask, float x, float y, LAYER layer, float radius);
std::vector<uint32_t> get_entities_overlapping_hitbox(std::vector<ENT_TYPE> entity_types, uint32_t mask, AABB hitbox, LAYER layer);
std::vector<uint32_t> get_entities_overlapping_hitbox(ENT_TYPE entity_type, uint32_t mask, AABB hitbox, LAYER layer);
std::vector<uint32_t> get_entities_overlapping(std::vector<ENT_TYPE> entity_types, uint32_t mask, float sx, float sy, float sx2, float sy2, LAYER layer);
std::vector<uint32_t> get_entities_overlapping(ENT_TYPE entity_type, uint32_t mask, float sx, float sy, float sx2, float sy2, LAYER layer);
std::vector<uint32_t> get_entities_overlapping_by_pointer(std::vector<ENT_TYPE> entity_types, uint32_t mask, float sx, float sy, float sx2, float sy2, Layer* layer);
std::vector<uint32_t> get_entities_overlapping_by_pointer(ENT_TYPE entity_type, uint32_t mask, float sx, float sy, float sx2, float sy2, Layer* layer);
void set_door_target(uint32_t id, uint8_t w, uint8_t l, uint8_t t);
std::tuple<uint8_t, uint8_t, uint8_t> get_door_target(uint32_t uid);
void set_contents(uint32_t uid, ENT_TYPE item_entity_type);
void entity_remove_item(uint32_t id, uint32_t item_uid);
bool entity_has_item_uid(uint32_t uid, uint32_t item_uid);
bool entity_has_item_type(uint32_t uid, std::vector<ENT_TYPE> entity_types);
bool entity_has_item_type(uint32_t uid, ENT_TYPE entity_type);
std::vector<uint32_t> entity_get_items_by(uint32_t uid, std::vector<ENT_TYPE> entity_types, uint32_t mask);
std::vector<uint32_t> entity_get_items_by(uint32_t uid, ENT_TYPE entity_type, uint32_t mask);
void lock_door_at(float x, float y);
void unlock_door_at(float x, float y);
uint32_t get_frame_count();
void carry(uint32_t mount_uid, uint32_t rider_uid);
void kill_entity(uint32_t uid, std::optional<bool> destroy_corpse = std::nullopt);
void destroy_entity(uint32_t uid);
void apply_entity_db(uint32_t uid);
void flip_entity(uint32_t uid);
std::pair<float, float> get_camera_position();
void set_camera_position(float cx, float cy);
void warp(uint8_t w, uint8_t l, uint8_t t);
void set_seed(uint32_t seed);
void set_arrowtrap_projectile(ENT_TYPE regular_entity_type, ENT_TYPE poison_entity_type);
void modify_sparktraps(float angle_increment = 0.015, float distance = 3.0);
void set_kapala_blood_threshold(uint8_t threshold);
void set_kapala_hud_icon(int8_t icon_index);
void set_blood_multiplication(uint32_t default_multiplier, uint32_t vladscape_multiplier);
SaveData* savedata();
std::vector<int64_t> read_prng();
void pick_up(uint32_t who_uid, uint32_t what_uid);
void drop(uint32_t who_uid, uint32_t what_uid);
void set_olmec_phase_y_level(uint8_t phase, float y);
void set_ghost_spawn_times(uint32_t normal = 10800, uint32_t cursed = 9000);
void set_drop_chance(uint16_t dropchance_id, uint32_t new_drop_chance);
void replace_drop(uint16_t drop_id, ENT_TYPE new_drop_entity_type);
void generate_particles(uint32_t particle_emitter_id, uint32_t uid);
void set_journal_enabled(bool b);
void set_camp_camera_bounds_enabled(bool b);
uint8_t waddler_count_entity(ENT_TYPE entity_type);
int8_t waddler_store_entity(ENT_TYPE entity_type);
void waddler_remove_entity(ENT_TYPE entity_type, uint8_t amount_to_remove = 99);
int16_t waddler_get_entity_meta(uint8_t slot);
void waddler_set_entity_meta(uint8_t slot, int16_t meta);
uint32_t waddler_entity_type_in_slot(uint8_t slot);
int32_t spawn_companion(ENT_TYPE companion_type, float x, float y, LAYER layer);
uint8_t enum_to_layer(const LAYER layer);
uint8_t enum_to_layer(const LAYER layer, std::pair<float, float>& player_position);
bool entity_type_check(const std::vector<ENT_TYPE>& types_array, const ENT_TYPE find);
