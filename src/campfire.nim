import sequtils
import strutils
import algorithm
import json
import math

import glm

import campfire.bootstrap
import campfire.util
import campfire.pool
import campfire.tween

{.this:self.}

type SFX = enum
    sfxDrop
    sfxMove
    sfxGrab
    sfxLand
    sfxTakeoff
    sfxHeart
    sfxCross
    sfxSuccess
    sfxFailure
    sfxHyperdrive
    sfxEat
    sfxGlomp
    sfxBump
    sfxCursor
    sfxAborted

converter toInt*(sfx: SFX): SfxId =
    return sfx.SfxId

type ParticleKind = enum
    heartParticle
    crossParticle
    dustParticle
    bloodParticle

type Particle = object
    kind: ParticleKind
    pos: Vec2f
    vel: Vec2f
    ttl: float
    maxttl: float
    above: bool

type Object = ref object of RootObj
    killed: bool
    name: string
    description: string
    pos: Vec2i
    size: Vec2i

type Movable = ref object of Object
    originalPos: Vec2i
    lastPos: Vec2i
    alpha: float

type Message = object
    text: string
    step: int
    ttl: float

proc getViewPos(self: Movable): Vec2i =
    let currentPos = vec2f(float(pos.x * 16), float(pos.y * 16))
    let lastPos = vec2f(float(lastPos.x * 16), float(lastPos.y * 16))
    return tween.easeOutCubic(alpha, lastPos, currentPos - lastPos).vec2i + (if Object(self) == cursorObject: vec2i(0, -4) else: vec2i(0, 0))

proc dummyInit()
proc menuInit()
proc menuUpdate(dt: float)
proc menuDraw()

method draw(self: Object) {.base.} =
    discard

method update(self: Object, dt: float) {.base.} =
    discard

var camera: Vec2f
var objects: seq[Object]
var shake: float = 0.0
var time: float = 0.0
var messages: seq[Message]

var moveBuffer: seq[Vec2i]



proc dummyInit() =
    discard

proc menuInit() =
    discard

proc menuUpdate(dt: float) =
    if btnp(pcStart):
        discard
    discard

proc menuDraw() =
    discard

proc introInit() =
    discard

proc introUpdate(dt: float) =
    discard

proc introDraw() =
    discard

bootstrap.init()
bootstrap.run(introInit, introUpdate, introDraw)