from functools import lru_cache

wires = {}

@lru_cache(maxsize=None)
def get_wire(wire):
    try:
        return int(wire)
    except ValueError:
        pass
    
    if wire == 'b':
        return 956
    
    statement = wires[wire]
    
    if "AND" in statement:
        statement = statement.split("AND")
        return get_wire(statement[0].strip()) & get_wire(statement[1].strip())
    elif "OR" in statement:
        statement = statement.split("OR")
        return get_wire(statement[0].strip()) | get_wire(statement[1].strip())
    elif "LSHIFT" in statement:
        statement = statement.split("LSHIFT")
        return get_wire(statement[0].strip()) << get_wire(statement[1].strip())
    elif "RSHIFT" in statement:
        statement = statement.split("RSHIFT")
        return get_wire(statement[0].strip()) >> get_wire(statement[1].strip())
    elif "NOT" in statement:
        statement = statement.split("NOT")
        return ~get_wire(statement[1].strip())
    else:
        return get_wire(statement)
    
        

if __name__ == "__main__":

    with open("input.txt", "r") as file:
        while True:
            line = file.readline()
            if not line:
                break
            line = line.split("->")
            wires[line[1].strip()] = line[0].strip()
    value = get_wire('a')
    print(value)
    
