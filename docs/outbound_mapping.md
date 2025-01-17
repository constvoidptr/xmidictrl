# Outbound Mappings

Outbound mappings are used to set a status on your MIDI controller, such as highlight a button if a certain function
got activated in X-Plane.

All outgoing mappings are defined for each MIDI device individually using the parameter `mapping_out`.

## Example

```
title   = "Settings for my favourite aircraft"
version = "1.00"

# Behringer X-Touch Mini
[[device]]
name       = "Behringer X-Touch Mini"
port_in    = 0
port_out   = 1
mapping_out = [
  { ch = 11, cc = 18, type = "drf", dataref = "tbm900/lights/ap/hdg", value_on = "1", value_off = "0" },
  { ch = 11, cc = 19, type = "drf", dataref = "tbm900/lights/ap/apr", value_on = "1", value_off = "0" },
  { ch = 11, cc = 20, type = "drf", dataref = "tbm900/lights/ap/nav", value_on = "1", value_off = "0" },
  { ch = 11, cc = 22, type = "drf", dataref = "tbm900/lights/ap/alt", value_on = "1", value_off = "0" }
]
```

## Required Parameters

The following parameter is required for each mapping.

| Parameter | Description                            |
|-----------|----------------------------------------|
| ch        | MIDI Channel (Default Value = 11)      |
| type      | Specifies the mapping type (see below) |  

One of the following parameters is required, depending on the MIDI message type.

| Parameter | MIDI Message Type | Expected Parameter Value |
|-----------|-------------------|--------------------------|
| cc        | Control Change    | Control Change No Number |
| note      | Note On / Off     | Note Number              |
| pitch     | Pitch Bend        | Pitch Bend Number        |
| prg       | Program Change    | Program Change Number    |

## Optional Parameters

| Parameter | Description            |
|-----------|------------------------|
| sl        | Sublayer               |

## MIDI Type

Each mapping must specify the type of the outgoing MIDI message. XMidiCtrl can send Control Change, Program Change,
Pitch Bend and Note On/Off messages.

A mapping must contains exactly one of the following variables.

| Variable | Description              |
|----------|--------------------------|
| cc       | Control Change No Number |
| note     | Note On/Off Number       |
| pitch    | Pitch Bend Number        |
| prg      | Program Change Number    |

## Mapping Types

The following mapping types are supported:

| Mapping Type |   Name    | Description and usage                                            |
|:------------:|:---------:|------------------------------------------------------------------|
|     drf      | Dataref   | Reads the dataref value and sends a MIDI message if necessary    |
|     con      | Constant  | Sends a constant velocity to the MIDI device                     |
|     sld      | Slider    | Sends a veloctiy based on a dataref to control motorized sliders | 

