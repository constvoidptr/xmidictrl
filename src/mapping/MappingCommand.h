//---------------------------------------------------------------------------------------------------------------------
//   MIT License
//
//   Copyright (c) 2021 Marco Auer
//
//   Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
//   documentation files (the "Software"), to deal in the Software without restriction, including without limitation
//   the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and
//   to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//   The above copyright notice and this permission notice shall be included in all copies or substantial portions of
//   the Software.
//
//   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//   THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
//   CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//   IN THE SOFTWARE.
//---------------------------------------------------------------------------------------------------------------------

#ifndef MAPPINGCOMMAND_H
#define MAPPINGCOMMAND_H

// Standard
#include <string>
#include <string_view>

// XMidiCtrl
#include "Mapping.h"
#include "MidiEvent.h"

namespace XMidiCtrl {

class MappingCommand : public Mapping {
public:
    explicit MappingCommand(XPlane::ptr xplane, int controlChange);
    ~MappingCommand() override = default;

    MappingType type() override;

    void setCommand(std::string_view command);
    [[nodiscard]] std::string_view command() const;

    bool check() override;
    void execute(MidiEvent::ptr midiEvent) override;

private:
    std::string m_command;
};

} // Namespace XMidiCtrl

#endif // MAPPINGCOMMAND_H