import build.loboutils as L


print L.help()

w = L.Widget(0, 0, 10, 20)

print w.x
w.move(10, 5)
print w.x, w.y, w.width, w.height
print 'right', w.right


l = L.Label('Label A', 1, 2, 5, 10)
print l.name, l.x, l.y, l.width, l.height
