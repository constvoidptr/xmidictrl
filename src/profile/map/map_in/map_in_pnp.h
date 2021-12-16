//---------------------------------------------------------------------------------------------------------------------
//   XMidiCtrl - MIDI Controller plugin for X-Plane
//
//   Copyright (c) 2021-2022 Marco Auer
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

#ifndef MAP_IN_PNP_H
#define MAP_IN_PNP_H

// Standard
#include <memory>
#include <string>

// toml11
#include <toml.hpp>

// XMidiCtrl
#include "map_in.h"
#include "midi_message.h"
#include "types.h"

namespace xmidictrl {

enum class CommandType {
    Push,
    Pull
};

class map_in_pnp : public map_in {
public:
    explicit map_in_pnp(xplane::ptr xp);
    ~map_in_pnp() override = default;

    typedef std::shared_ptr<map_in_pnp> ptr;

    map_type type() override;

    void set_command_push(std::string_view command);
    [[nodiscard]] std::string_view command_push() const;

    void set_command_pull(std::string_view command);
    [[nodiscard]] std::string_view command_pull() const;

    void set_command_type(CommandType commandType);

    void read_config(toml::value &settings) override;
    bool check() override;

    void execute(midi_message &msg) override;

private:
    CommandType m_command_type {CommandType::Push};

    std::string m_command_push {};
    std::string m_command_pull {};
};

} // Namespace xmidictrl

#endif // MAP_IN_PNP_H