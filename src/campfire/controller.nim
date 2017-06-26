import sdl2
import sdl2.gamecontroller

type ControllerKind* = enum
    Keyboard
    Gamepad

type ControllerAxis* = enum
    pcXAxis
    pcYAxis
    pcLTrigger
    pcRTrigger

type ControllerButton* = enum
    pcUp
    pcDown
    pcLeft
    pcRight
    pcA
    pcB
    pcX
    pcY
    pcLB
    pcLT
    pcRB
    pcRT
    pcStart
    pcBack

type Controller* = ref object of RootObj
    kind*: ControllerKind
    name*: string
    sdlController*: GameControllerPtr
    sdlControllerId*: int
    axes*: array[ControllerAxis.low..ControllerAxis.high, tuple[current, previous: float]]
    buttons*: array[ControllerButton.low..ControllerButton.high, int]

proc newController*(sdlControllerId: cint): Controller =
    result = new(Controller)
    result.sdlControllerId = sdlControllerId
    if sdlControllerId > -1:
        result.sdlController = gameControllerOpen(sdlControllerId)
        if result.sdlController == nil:
            raise newException(Exception, "error opening game controller: " & $sdlControllerId)
        result.kind = Gamepad
        result.name = $result.sdlController.name
    else:
        result.kind = Keyboard
        result.name = "KEYBOARD"
    echo "added game controller: ", sdlControllerId, ": ", result.kind, ": ", result.name

proc update*(self: Controller) =
    for i in 0..self.buttons.high:
        if self.buttons[i] >= 1:
            self.buttons[i] += 1
        if self.buttons[i] > 48:
            self.buttons[i] = 1

proc postUpdate*(self: Controller) = 
    for i in 0..self.axes.high:
        self.axes[i].previous = self.axes[i].current

proc btn*(self: Controller, button: ControllerButton): bool = 
    return self.buttons[button] > 0

proc btnp*(self: Controller, button: ControllerButton): bool =
    return self.buttons[button] == 2

#[

]#
proc setButtonState*(self: Controller, button: ControllerButton, down: bool) =
    if button > ControllerButton.high:
        return
    self.buttons[button] = if down: 1 else: 0

proc setAxisValue*(self: Controller, axis: ControllerAxis, value: float) =
    if axis > ControllerAxis.high:
        return
    self.axes[axis].current = value

#[
    Get Axis' current value
]#
proc axis*(self: Controller, axis: ControllerAxis): float =
    return self.axes[axis].current

#[
    dunno what's this for
]#
proc axisp*(self: Controller, axis: ControllerAxis, value: float): bool =
    if value == -1.0:
        return self.axes[axis].current < -0.5 and not (self.axes[axis].previous < -0.5)
    elif value == 1.0:
        return self.axes[axis].current > 0.5 and not (self.axes[axis].previous < -0.5)
    elif value == 0.0:
        return abs(self.axes[axis].current) < 0.5 and not (abs(self.axes[axis].previous) < 0.5)
        