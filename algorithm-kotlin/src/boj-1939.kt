import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val (N, M) = readLine().split(' ').map { it.toInt() }
    val adj = List<MutableList<Pair<Int,Long>>>(N+1){ arrayListOf() }
    repeat(M) {
        val (a, b, c) = readLine().split(' ').map { it.toInt() }
        adj[a] += (b to c.toLong())
        adj[b] += (a to c.toLong())
    }
    val (src, trg) = readLine().split(' ').map { it.toInt() }
    val que : Queue<Pair<Int,Long>> = LinkedList()
    fun decision(k : Long) : Boolean{
        val visited = BooleanArray(N+1){false}
        que += (src to 0L)
        visited[src] = true
        while(que.isNotEmpty()) {
            val p = que.poll()
            if(p.first == trg) return true
            visited[p.first] = true
            adj[p.first].forEach { q ->
                if(!visited[q.first] && q.second >= k){
                    que += q
                }
            }
        }
        return false
    }

    fun optimize() : Long{
        var lo = -1L
        var hi = 1e9.toLong()+1
        while(lo + 1 < hi) {
            val mid = (lo + hi) / 2
            if(decision(mid))
                lo = mid
            else
                hi = mid
        }
        return lo
    }
    println(optimize())
}