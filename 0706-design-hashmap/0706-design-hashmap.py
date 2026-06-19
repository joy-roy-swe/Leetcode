class MyHashMap:

    def __init__(self):
        self.map_data = [-1] * 10_000_000

    def put(self, key: int, value: int) -> None:
        self.map_data[key]=value

    def get(self, key: int) -> int:
        if self.map_data[key] == -1:
            return -1
        return self.map_data[key]

    def remove(self, key: int) -> None:
        self.map_data[key]=-1

        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)