import java.io.BufferedReader
import java.io.InputStreamReader

/**
 * 아니 이거 맞는데 코틀린 코드만 틀림.. 입력값이 뭔가 문제가 있는듯
 */
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val (R, C) = readLine().split(' ').map { it.toInt() }
    val PC = readLine().toInt()
    val WC = readLine().toInt()
    val colList = mutableListOf<Int>()
    var maxRow = 0
    repeat(WC) {
        val (r, c) = readLine().trim().split(' ').map { it.toInt() }
        maxRow = maxOf(maxRow, r)
        colList += c
    }
    colList.sort()
    fun decision(k : Int) : Boolean{
        var st = -1
        var cnt = 0
        colList.forEach {
            if(st == -1) {
                st = it
                cnt++
            }else if(it - st >= k) {
                st = it
                cnt++
            }
        }
        return cnt <= PC
    }
    fun optimize() : Int {
        var lo = minOf(maxRow, C) - 1
        var hi = maxOf(R, C) + 1
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