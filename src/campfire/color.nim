import sdl2

proc makeColor(r, g, b, a: int): Color =
    return (uint8(r), uint8(g), uint8(b), uint8(a))

var colors*: array[16, Color] = [
    makeColor(0, 0, 0, 255),
    makeColor(157, 157, 157, 255),
    makeColor(255, 255,255,255),
    makeColor(190, 38, 51, 255),
    makeColor(224, 111, 139, 255),
    makeColor(73, 60, 43, 255),
    makeColor(164, 100, 34, 255),
    makeColor(235, 137, 49, 255),
    makeColor(247, 226, 107, 255),
    makeColor(47, 72, 78, 255),
    makeColor(68, 137, 26, 255),
    makeColor(163, 206, 39, 255),
    makeColor(27, 38, 50, 255),
    makeColor(0, 87, 132, 255),
    makeColor(49, 162, 242, 255),
    makeColor(178, 220, 239, 255),
]