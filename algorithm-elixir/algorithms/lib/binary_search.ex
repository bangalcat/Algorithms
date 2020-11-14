defmodule BinarySearch do
  # boj 1300번 문제 풀이
  # key가 item보다 작거나 같으면
  def decision(n, k, mid) do
    1..n
    |> Enum.map(&min(n, div(mid, &1)))
    |> Enum.sum()
    |> Kernel.>=(k)
  end

  def binary_search(_n, lo, hi, _key) when lo == hi, do: lo

  def binary_search(n, lo, hi, key) do
    # B[k] 값을 key로 놓고 그보다 작은 i * j의 개수가 index로써 비교된다.
    mid = div(lo + hi, 2)

    cond do
      # 현재 mid의 index가 k보다 더 크거나 같다면 hi를 좁힌다.
      decision(n, key, mid) -> binary_search(n, lo, mid, key)
      true -> binary_search(n, mid + 1, hi, key)
    end
  end

  def solver(n, k) do
    binary_search(n, 1, n * n + 1, k)
  end
end
