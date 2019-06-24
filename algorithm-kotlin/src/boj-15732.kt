import java.io.BufferedReader
import java.io.InputStreamReader

data class Nuts(val a : Int, val b : Int, val c : Int)

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val (N, K, D) = readLine().split(' ').map { it.toInt() }
    val nuts = mutableListOf<Nuts>()

    for(i in 0 until K) {
        val (a,b,c) = readLine().split(' ').map { it.toInt() }
        nuts.add(Nuts(a,b,c))
    }
    fun decision(k : Int) : Boolean{
        var cnt = 0
        for(nut in nuts) {
            if(nut.a > k) continue
            cnt += ((Math.min(nut.b, k) - nut.a) / nut.c + 1)
            if(cnt >= D)
                return true
        }
        return cnt >= D
    }
    fun optimize() : Int {
        var lo = nuts.minBy { it.a }!!.a - 1
        var hi = N + 1
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