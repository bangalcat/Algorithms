import java.io.BufferedReader
import java.io.FileReader
import java.io.InputStreamReader
import java.util.*

// 숨박꼭질

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
//fun main() = with(BufferedReader(FileReader("src/input.in"))){
    val (N, K) = readLine().split(' ').map { it.toInt() }

    val visit = IntArray(100001){-1}
    val que = LinkedList<Int>()
    que.push(N)
    visit[N] = 0
    fun solve() : Int {
        while (que.isNotEmpty()) {
            val f = que.poll()
            if (f == K) return visit[f]
            if (f - 1 >= 0 && visit[f - 1] == -1) {
                visit[f - 1] = visit[f] + 1
                que.push(f - 1)
            }
            if (f+1 <= 100000 && visit[f + 1] == -1) {
                visit[f + 1] = visit[f] + 1
                que.push(f + 1)
            }
            if (f * 2 <= 100000 && visit[f * 2] == -1) {
                visit[f * 2] = visit[f] + 1
                que.push(f * 2)
            }
        }
        return visit[K]
    }
    println(solve())
}