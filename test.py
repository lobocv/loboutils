import build.loboutils as L


print L.help()

w = L.Widget(0, 0, 10, 20)



print w.x
w.move(10, 5)
print w.x, w.y

print 'right', w.right
