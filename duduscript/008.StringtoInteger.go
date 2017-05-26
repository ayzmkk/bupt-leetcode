import "bytes"

func myAtoi(str string) int {
    if len(str) == 0 { return 0 }
    if str[0] == ' '{
        return myAtoi(str[1:])
    }
    var buf bytes.Buffer
    flagnum := 0
    for i := 0; i < len(str); i++ {
        if str[i] == '+' || str[i] == '-' {
            flagnum++
            if flagnum >= 2 {
                return 0
            }
        } else if tmp := int(str[i]) - int('0'); tmp <0||tmp>9 {
            break
        }
        buf.WriteByte(str[i])
    }
    str = buf.String()
    if len(str) == 0 || flagnum != 0 && str[0] != '+' && str[0] != '-' {
        return 0
    }
    flag := 0
    if str[0] == '-' {
        flag = 1
        str = str[1:]
    } else if str[0] == '+' {
        str = str[1:]
    }
    result := 0
    for i := 0; i< len(str); i++ {
        result = result*10 + int(str[i]) - int('0')
        if result >= (1<<31) { break }
    }
    if flag == 1 { result = -result }
    if result > (1<<31)-1 { 
        return (1<<31)-1
    }
    if result < -(1<<31) { 
        return -(1<<31)
    }
    return result
}