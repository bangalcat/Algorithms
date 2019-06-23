package ref

// 좋았던 정답 코드

import java.io.BufferedReader
import java.io.InputStreamReader

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    var (n, atk) = readLine().split(' ').map { it.toLong() }
    var hp = 0L
    var maxd = 0L

    /*
     *  와 어떻게 이렇게 풀지?
     */
    repeat(n.toInt()) {
        val (t, a, h) = readLine().split(' ').map { it.toLong() }

        if (t == 1L) {
            val minus = ((h - 1) / atk) * a
            hp += minus

            maxd = Math.max(hp, maxd)
        } else {
            atk += a
            hp -= h
            if (hp < 0L) hp = 0L
        }
    }

    println(maxd + 1)
}
