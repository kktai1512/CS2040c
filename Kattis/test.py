def foo(x):
    return lambda y: y+2

print(foo(9)(2))