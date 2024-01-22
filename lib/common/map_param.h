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

#ifndef XMC_MAP_PARAM_H
#define XMC_MAP_PARAM_H

// Standard
#include <string>

// XMidiCtrl
#include "midi_message.h"
#include "text_logger.h"
#include "types.h"

namespace xmidictrl {

//---------------------------------------------------------------------------------------------------------------------
//   TYPES
//---------------------------------------------------------------------------------------------------------------------

/**
 * Defines if the params are for inbound or outbound mappings
 */
enum class map_param_type {
	in,
	out
};




//---------------------------------------------------------------------------------------------------------------------
//   CLASS
//---------------------------------------------------------------------------------------------------------------------

class map_param {
public:
	explicit map_param(std::string_view in_sl_value);

	std::string_view sl_value();

	virtual map_param_type type() = 0;

private:
	//std::shared_ptr<midi_message> msg;
	//text_logger& log;

	std::string m_sl_value;

	//outbound_send_mode send_mode {outbound_send_mode::permanent};
};

} // Namespace xmidictrl

#endif // XMC_MAP_PARAM_H
