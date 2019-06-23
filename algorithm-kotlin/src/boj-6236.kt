import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val (N, M) = readLine().split(' ').filter{ it.isNotEmpty() }.map { it.toInt() }
    val dayCosts = IntArray(N)
    for(i in 0 until N)
        dayCosts[i] = readLine().toInt()

    fun decision(k : Int) : Boolean {
        var ret = 0
        var remain = 0
        dayCosts.forEach {
            if(remain < it) {
                remain = k - it
                ret++
            }else {
                remain -= it
            }
        }
        return ret <= M
    }
    fun optimize() : Int{
        var lo = (dayCosts.max()?:0).minus(1)
        var hi = 10000 * 100000 + 1
        while(lo + 1 < hi) {
            val mid = (lo + hi) / 2
//            println("$lo $hi $mid")
            if(decision(mid))
                hi = mid
            else
                lo = mid
        }
        return hi
    }
    println(optimize())
}