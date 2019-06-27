import glm
import strutils
import json
import algorithm
import sequtils
import math

import campfire.bootstrap
import campfire.entity
import campfire.util
import campfire.tween
import campfire.pool

{.this:self.}

type SFX = enum
  sfxStart
  sfxMove

converter toInt*(sfx: SFX): SfxId =
  return sfx.SfxId

type ParticleKind = enum
  heartParticle

type Particle = object
  kind: ParticleKind
  pos: Vec2f
  vel: Vec2f
  ttl: float
  maxttl: float
  above: bool

type Message = object
  text: string
  step: int
  ttl: float

type Movable = ref object of Entity
  original: Vec2i
  lastPos: Vec2i
  alpha: float

# GLOBALS
var levelId: int
var nextLevelId: int
var previousLevelId: int = -1
var unlockedLevel: float
var levelsCompleted: array[32, int]
var alpha = 0.0
var cursorObject: Entity
var shake: float = 0.0
var time: float = 0.0
var scanning: bool
var particles: Pool[Particle]
var confirmAbort: bool
var messages: seq[Message]

var camera: Vec2f

proc getViewPos(self: Movable): Vec2i =
  let currentPos = vec2f(float(pos.x * 16), float(pos.y * 16))
  let lastPos = vec2f(float(lastPos.x * 16), float(lastPos.y * 16))
  return tween.easeOutCubic(alpha, lastPos, currentPos - lastPos).vec2i

proc gameInit() =
  particles = initPool[Particle](512)
  time = 0.0

proc gameUpdate(dt: float) =
  time += dt

proc gameDraw() =
  # background
  setCamera()
  cls()

proc introInit() =
  gameInit()

proc introUpdate(dt: float) =
  if btn(pcB):
    echo true
  discard

proc introDraw() =
  discard

bootstrap.init("Campfire")
bootstrap.run(introInit, introUpdate, introDraw)