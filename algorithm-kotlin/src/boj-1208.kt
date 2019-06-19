import java.io.BufferedReader
import java.io.InputStreamReader

// 부분수열의 합2

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val (N, S) = readLine().split(' ').map { it.toInt() }
    val arr = readLine().split(' ').filter { it.isNotEmpty() }.map {it.toInt()}.toIntArray().sortedArray()

    fun pick(sum : Int, idx : Int) : Int{
        if(idx >= N) return 0
        return (if(sum + arr[idx] == S) 1 else 0) + pick(sum + arr[idx], idx + 1) + pick(sum, idx + 1)
    }

    println(pick(0, 0))
}
