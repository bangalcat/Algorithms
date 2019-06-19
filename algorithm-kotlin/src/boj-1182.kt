import java.io.BufferedReader
import java.io.InputStreamReader

// 부분 수열의 합

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val (N, S) = readLine().split(' ').map { it.toInt() }
    val arr = readLine().split(' ').map {it.toInt()}.toIntArray()

    var ret = 0
    fun pick(sum : Int, idx : Int) {
        if(idx >= N) return
        if(sum + arr[idx] == S)
            ret++
        pick(sum + arr[idx], idx + 1)
        pick(sum, idx + 1)
    }
    pick(0, 0)

    println(ret)
}