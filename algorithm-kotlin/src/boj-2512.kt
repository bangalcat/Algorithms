import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val N = readLine().toInt()
    val budgets = readLine().split(' ').filter { it.isNotEmpty() }.map { it.toInt() }
    val M = readLine().toInt()

    fun decision(upperLimit : Int) : Boolean{
        var ret = 0L
        budgets.forEach {
            ret +=
                if(it > upperLimit)
                    upperLimit
                else
                    it
        }
        return ret <= M
    }

    fun optimize() : Int {
        var lo = -1
        var hi = (budgets.max()?:0) + 1
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