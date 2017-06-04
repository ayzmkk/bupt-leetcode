import "bytes"

func generateParenthesis(n int) []string {
    if n == 0 {
        return []string{""}
    }
    var result []string
    for i:=0;i<n;i++ {
        subin := generateParenthesis(i)
        subr := generateParenthesis(n-i-1)
        for j:=0;j<len(subin);j++ {
            for k:=0;k<len(subr);k++ {
                var buf bytes.Buffer
                buf.WriteString("(")
                buf.WriteString(subin[j])
                buf.WriteString(")")
                buf.WriteString(subr[k])
                result = append(result, buf.String())
            }
        }
    }
    return result
}