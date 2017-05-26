import "bytes"
func letterCombinations(digits string) []string {
    table := map[byte]string {
        '2' : "abc",
        '3' : "def",
        '4' : "ghi",
        '5' : "jkl",
        '6' : "mno",
        '7' : "pqrs",
        '8' : "tuv",
        '9' : "wxyz",
    }
    var result []string
    for i:=0;i<len(digits);i++ {
        if digits[i] == '0' || digits[i] == '1' { continue }
        var tmp []string
        for j:=0;j<len(table[digits[i]]);j++ {
            if len(result) == 0 {
                tmp = append(tmp, string(table[digits[i]][j]))
                continue
            }
            for k:=0;k<len(result);k++ {
                b := bytes.NewBufferString(result[k])
                b.WriteByte(table[digits[i]][j])
                tmp = append(tmp, b.String())
            }
        }
        result = tmp
    }
    return result
}