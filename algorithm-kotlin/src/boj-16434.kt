import java.io.BufferedReader
import java.io.InputStreamReader

data class RoomInfo(val type : Int, val a : Long, val h : Long)

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (N, A) = readLine().split(' ').map { it.toInt() }
    val roomsInfo : MutableList<RoomInfo> = mutableListOf()
    for(i in 1..N) {
        val (t, a, h) = readLine().split(' ').map { it.toInt() }
        roomsInfo += RoomInfo(t,a.toLong(),h.toLong())
    }
    fun decision(maxH : Long) : Boolean {
        var curH = maxH
        var curA = A.toLong()
        roomsInfo.forEach {
            if(it.type == 2){
                curH = Math.min(curH + it.h, maxH)
                curA += it.a
            } else {
                var aTime = Math.min(it.h / curA, curH / it.a)
                if(aTime != 0L) aTime--
                var mH = it.h - (curA * aTime)
                curH -= (it.a * aTime)
                while(true){
                    mH -= curA
                    if(mH <= 0) break
                    curH -= it.a
                    if(curH <= 0) return false
                }
            }
        }
        return true
    }
    fun optimize() : Long{
        var lo = 0L
        var hi = 1e12.toLong() * 123456L + 1
        while(lo + 1 < hi) {
            val mid = (lo + hi) / 2
            if(decision(mid))
                hi = mid
            else
                lo = mid
        }
        return hi
    }
    println(optimize())
}
