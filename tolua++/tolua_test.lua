function functionA(a, b)
    print("lua: functionA()")
    return a+b
end

function functionB(obj)
    print("lua: functionB()")
    SetNumber(obj, 100)
    local result = GetNumber(obj)
    print("lua: c++.GetNumber() result: "..result)
end
