func romanToInt(s string) int {
    table := [][]string {
        {"","I","II","III","IV","V","VI","VII","VIII","IX" },
        {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" },
        {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" },
        {"","M","MM","MMM" }}
    result,index,num := 0,0,1000
    for index < len(s) {
        for i := 3;i >= 0; i-- {
            for j := len(table[i])-1 ;j > 0; j-- {
                if strings.HasPrefix(s[index:],table[i][j]) {
                    result += num*j
                    index += len(table[i][j])
                    break
                }
            }
            num /= 10
        }
    }
    return result
}