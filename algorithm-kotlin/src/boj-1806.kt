import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.min

// 부분합

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val (N, S) = readLine().split(' ').map { it.toInt() }
    val arr = readLine().split(' ').filter { it.isNotEmpty() }.map {it.toInt()}.toIntArray()

    var ret = N + 1
    var l = 0
    var sum = 0
    for ((i, num) in arr.withIndex()) {
        sum += num
        if(sum >= S) {
            while(sum >= S && l <= i) {
                ret = min(ret, i - l + 1)
                sum -= arr[l++]
            }
        }
    }
    println(if(ret==N+1) 0 else ret)
}
