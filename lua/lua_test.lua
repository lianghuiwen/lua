function functionA(a, b)
    print("lua: functionA()")
    return a+b
end

function functionB(obj)
    print("lua: functionB()")
    local result = Sum(10, 20, 30)
    print("lua: c++.sum() result: "..result)
end
