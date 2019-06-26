import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val (N, M, L) = readLine().split(' ').map { it.toInt() }
    val point = mutableListOf<Int>()
    for(i in 1..M) point += readLine().toInt()
    fun decision(n : Int, len : Int) : Boolean{
        var last = 0
        var cnt = 0
        point.forEach {
            if(it - last >= len && L - it >= len){
                last = it
                cnt++
            }
        }
        return cnt >= n
    }
    fun optimize(n : Int) : Int {
        var lo = 0
        var hi = L + 1
        while(lo + 1 < hi) {
            val mid = (lo + hi) / 2
            if(decision(n, mid))
                lo = mid
            else
                hi = mid
        }
        return lo
    }
    for(i in 1..N) {
        val q = readLine().toInt()
        println(optimize(q))
    }

}