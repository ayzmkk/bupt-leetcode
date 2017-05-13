func convert(s string, numRows int) string {
    if numRows == 1 { return s }
    mp := make([][]byte,numRows)
    var buf bytes.Buffer
    line := 0
    for i:=0;i<len(s);i++ {
        mp[line] = append(mp[line],s[i])
        if i == 0 || (i/(numRows-1))%2==0 {
            line++
        } else {
            line--
        }
    }
    for i:=0;i<numRows;i++ {
        for j:=0;j<len(mp[i]);j++ {
            buf.WriteByte(mp[i][j])
        }
    }
    return buf.String()
}