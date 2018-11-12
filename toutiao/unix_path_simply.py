def solve(path):
        
    paths = path.split("/")
    stack = []
    result = ""
    for p in paths:
        if p not in ["",".",".."]:  # 需要处理
            stack.append(p) 
        if ".." == p and stack: 
            stack.pop(-1)
    if []==stack: 
        return "/"

    for s in stack:
        result += "/"+s 
    return result

if __name__=='__main__':
    
    s=input('')
    
    print(solve(s))
    