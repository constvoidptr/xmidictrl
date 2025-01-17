//---------------------------------------------------------------------------------------------------------------------
//   XMidiCtrl - MIDI Controller plugin for X-Plane
//
//   Copyright (c) 2021-2024 Marco Auer
//
//   XMidiCtrl is free software: you can redistribute it and/or modify it under the terms of the
//   GNU Affero General Public License as published by the Free Software Foundation, either version 3
//   of the License, or (at your option) any later version.
//
//   XMidiCtrl is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
//   the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU Affero General Public License for more details.
//
//   You should have received a copy of the GNU Affero General Public License along with XMidiCtrl.
//   If not, see <https://www.gnu.org/licenses/>.
//---------------------------------------------------------------------------------------------------------------------

#ifndef XMC_SETTINGS_WINDOW_H
#define XMC_SETTINGS_WINDOW_H

// XMidiCtrl
#include "environment.h"
#include "imgui_window.h"
#include "settings.h"

namespace xmidictrl {

class settings_window : public imgui_window {
public:
	settings_window(text_logger& in_log, environment& in_env);
	~settings_window() override = default;

protected:
	void create_widgets() override;

private:
	void create_tab_general();
	void create_tab_midi();
	void create_tab_logging();
	void create_tab_paths();

	static std::string info_position_as_text(window_position in_position);
	void save_settings();

	bool m_debug_mode;
	bool m_log_midi;
	bool m_show_errors;

	int m_virtual_channel;
	float m_default_outbound_delay;

	int m_max_text_messages;
	int m_max_midi_messages;

	int m_note_name;

	int m_default_text_sort;
	int m_default_midi_sort;

	bool m_use_common_profile;

	bool m_info_disabled;
	window_position m_info_position;
	int m_info_offset_x;
	int m_info_offset_y;
	int m_info_seconds;

	std::string m_path_xplane;
	std::string m_path_plugin;
	std::string m_path_preferences;
	std::string m_path_profiles;
	std::string m_path_includes;
};

} // Namespace xmidictrl

#endif // XMC_SETTINGS_WINDOW_H