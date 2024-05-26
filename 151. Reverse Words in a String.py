class Solution(object):
    def reverseWords(self, s):
        def reverse(words):
            new_list = []
            for i in range (len(words)-1, -1, -1):
                    new_list.append(words[i])
            return new_list

        list_words = s.split()
        empty = reverse(list_words)
        return ' '.join(empty)