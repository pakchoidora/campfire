import sdl2
import "lib/stb_image"

type
  Font* = ref object
    rects*: array[256, Rect]
    surface*: SurfacePtr

proc setFont*(canvas: SurfacePtr, filename: string, chars: string): Font =
  var font = new(Font)
  var w,h: cint
  var components: Components
  var raw_pixels = load(filename.cstring(), addr(w), addr(h), addr(components), RgbAlpha)
  if raw_pixels == nil:
    echo "error loading font: ", filename
    quit(1)
  var pixels = cast[ptr array[uint32.high, uint8]](raw_pixels)

  # load pixels into a texture
  var surface = createRGBSurfaceFrom(pixels, w, h, 32, w*4, 0xff000000'u32, 0x00ff0000'u32, 0x0000ff00'u32, 0x000000ff'u32)
  font.surface = convertSurface(surface, canvas.format, 0)
  if font.surface == nil:
    echo getError()
    quit(1)

  var newChar = false
  let blankColor: Color = (pixels[0],pixels[1],pixels[2],pixels[3])
  var currentRect: Rect = (cint(0),cint(0),cint(0),cint(0))
  var i = 0
  let stride = w*4
  for x in 0..w-1:
    let color: Color = (pixels[x*4],pixels[x*4+1],pixels[x*4+2],pixels[x*4+3])
    if color == blankColor:
      currentRect.w = x - currentRect.x
      if currentRect.w != 0:
        # go down until we find blank or h
        currentRect.h = h-1
        for y in 0..h-1:
          let color: Color = (pixels[y*stride+x*4],pixels[y*stride+x*4+1],pixels[y*stride+x*4+2],pixels[y*stride+x*4+3])
          if color == blankColor:
            currentRect.h = y - 2
        font.rects[cast[uint](chars[i])] = currentRect
        i += 1
      newChar = true
      currentRect.x = x + 1
  return font