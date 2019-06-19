import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

// 백준 1987

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))){
    val (R, C) = readLine().split(' ').map{it.toInt()}

    val dr = intArrayOf(1,0,-1,0)
    val dc = intArrayOf(0,1,0,-1)

    fun isRange(r : Int, c : Int) : Boolean = r in 0..(R - 1) && c in 0..(C - 1)

    val board = Array(R) { "" }
    val check = BooleanArray(26,{false})

    for(i in 0 until R) {
        board[i] = readLine()
    }
    var ans = 0
    //    check[board[0][0]-'A'] = true
    fun go(r : Int, c : Int, cnt : Int) {
        if(check[board[r][c]-'A']) {
            ans = max(cnt, ans)
            return
        }
        check[board[r][c]-'A'] = true
        for(d in 0..3){
            if(isRange(r+dr[d], c+dc[d])) {
                go(r+dr[d], c+dc[d], cnt + 1)
            }
        }
        check[board[r][c]-'A'] = false
    }
    go(0, 0, 0)
    println(ans)
}