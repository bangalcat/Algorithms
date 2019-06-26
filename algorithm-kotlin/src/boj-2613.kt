import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val (N, M) = readLine().split(' ').map { it.toInt() }
    val marbles = readLine().split(' ').map{it.toInt()}

    fun decision(maxV : Int) : Int {
        var sum = 0
        var cnt = 1
        marbles.forEach {
            if(sum + it > maxV) {
                sum = it
                if(++cnt > M) return 0
            }else
                sum += it
        }
        return cnt
    }

    fun optimize() : Int {
        var lo = marbles.max()!! - 1
        var hi = marbles.sum() + 1
        while(lo + 1 < hi) {
            val mid = (lo + hi) / 2
            if(decision(mid) > 0)
                hi = mid
            else
                lo = mid
        }
        return hi
    }
    val ans = optimize()

    fun printGroup(a : Int) {
        var sum = 0
        var cnt = 0
        val ret = mutableListOf<Int>()
        marbles.forEach {
            if(sum + it > a){
                ret.add(cnt)
                sum = it
                cnt = 1
            }else {
                sum += it
                cnt++
            }
        }
        ret.add(cnt)
        while(ret.size < M) {
            val idx = ret.withIndex().maxBy { it.value }!!
            ret[idx.index] = idx.value - 1
            ret += 1
        }
        ret.forEach {
            print("$it ")
        }
    }

    println(ans)
    printGroup(ans)
}
