import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val (N, M) = readLine().split(' ').map { it.toInt() }
    val lessons = readLine().split(' ').map { it.toInt() }

    fun decision(len : Int) : Boolean{
        var temp = 0
        var cnt = 1
        lessons.forEach {
            when {
                temp + it <= len -> temp += it
                it > len -> return false
                else -> {
                    temp = it
                    cnt++
                }
            }
        }
        return cnt <= M
    }
    fun optimize() : Int {
        var lo = (lessons.max()?:0) - 1
        var hi = lessons.sum() + 1
        while(lo + 1 < hi) {
//        for(iter in 1..100){
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