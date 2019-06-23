import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val (K, N) = readLine().split(' ').filter{ it.isNotEmpty() }.map { it.toInt() }
    val lanCables = LongArray(K)
    for(i in 0 until K)
        lanCables[i] = readLine().toLong()

    fun decision(len : Long) : Boolean {
        var ret = 0L
        lanCables.forEach {
            ret += (it / len)
            if(ret >= N) return true
        }
        return ret >= N
    }
    fun optimize() : Int{
        var lo = 0L
        var hi = lanCables.sum().div(N) + 1
        while(lo + 1 < hi) {
            val mid = (lo + hi) / 2
//            println("$lo $hi $mid")
            if(decision(mid))
                lo = mid
            else
                hi = mid
        }
        return lo.toInt()
    }
    println(optimize())
}