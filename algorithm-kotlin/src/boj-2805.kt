import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val (N, M) = readLine().split(' ').map { it.toInt() }
    val treeHeights = readLine().split(' ').filter { it.isNotEmpty() }.map { it.toInt()}.toIntArray()
    fun decision(height : Int) : Boolean{
        var ret = 0L
        treeHeights.filter { it > height }.forEach {
            ret += (it - height)
        }
        return ret >= M
    }
    fun optimize() : Int{
        var lo = -1
        var hi = treeHeights.max()?:0 + 1
//        for(iter in 1..100) {
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