defmodule UnionFind do
  use Agent

  @moduledoc """

  ## Example

      iex> UnionFind.start_link(1000)
      {:ok, #PID<0.167.0>}
      iex> UnionFind.merge(1, 2)
      :ok
      iex> UnionFind.find(1)
      1
      iex> UnionFind.find(2)
      1
  """

  def start_link(n) do
    Agent.start_link(fn -> init(n) end, name: __MODULE__)
  end

  def init(n) do
    0..n |> Map.new(&{&1, &1})
  end

  def find(u) do
    Agent.get_and_update(__MODULE__, fn table -> do_find(u, table) end)
  end

  def merge(u, v) do
    Agent.update(__MODULE__, fn table -> do_merge(u, v, table) end)
  end

  def do_merge(u, v, table) do
    {u, table} = do_find(u, table)
    {v, table} = do_find(v, table)
    Map.put(table, v, u)
  end

  defp do_find(u, table) do
    if table[u] == u do
      {u, table}
    else
      do_find(table[u], Map.put(table, u, table[u]))
    end
  end
end
