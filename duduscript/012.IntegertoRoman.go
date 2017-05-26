import "bytes"
import "strconv"

func intToRoman(num int) string {
    s := []int { num%10, (num%100)/10, (num%1000)/100, num/1000 }
    var result bytes.Buffer
    table := [][]string {
        {"","I","II","III","IV","V","VI","VII","VIII","IX" },
        {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" },
        {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" },
        {"","M","MM","MMM" }}
    for i := 3; i >= 0; i-- {
        result.WriteString(table[i][s[i]])
    }
    return result.String()
}