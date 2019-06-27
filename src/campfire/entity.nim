import glm

type Entity* = ref object of RootObj
  killed: bool
  name: string
  description: string
  pos*: Vec2i
  size: Vec2i

method draw*(self: Entity) {.base.} =
  discard

method update*(self: Entity, dt: float) {.base.} =
  discard