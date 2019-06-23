import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val (N, C) = readLine().split(' ').map { it.toInt() }
    val house = IntArray(N)
    for(i in 0 until N)
        house[i] = readLine().toInt()
    house.sort()

    fun decision(dist : Int) : Boolean {
        var ret = 0
        var last = -1
        house.forEach {
            if( last == -1 ||  it - last >= dist) {
                ret++
                last = it
                if(ret == C) return true
            }
        }
        return false
    }
    fun optimize() : Int {
        var lo = -1
        var hi = 1e9.toInt() + 1
        while(lo + 1 < hi) {
            val mid = (lo + hi) / 2
//            println("$lo $hi $mid")
            if(decision(mid))
                lo = mid
            else
                hi = mid
        }
        return lo
    }
    println(optimize())
}