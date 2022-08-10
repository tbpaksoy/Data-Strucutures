namespace DataStructures
{
    public static class Sorting
    {
        private static int Partition(ref int[] resource, int low, int high)
        {
            int pivot = resource[high];
            int i = low - 1;
            for (int j = low; j <= high - 1; j++)
            {
                if (resource[j] < pivot)
                {
                    i++;
                    int a = resource[i];
                    resource[i] = resource[j];
                    resource[j] = a;
                }
            }
            int temp = resource[i + 1];
            resource[i + 1] = resource[high];
            resource[high] = temp;
            return i + 1;
        }
        public static void QuickSort(ref int[] resource, int low, int high)
        {
            if (low < high)
            {
                int pivot = Partition(ref resource, low, high);
                QuickSort(ref resource, low, pivot - 1);
                QuickSort(ref resource, pivot + 1, high);
            }
        }
        private static void TopDownSplitMerge(ref int[] b, int begin, int end, ref int[] a)
        {
            if (end - begin <= 1) return;
            int middle = (begin + end) / 2;
            TopDownSplitMerge(ref a, begin, middle, ref b);
            TopDownSplitMerge(ref a, middle, end, ref b);
            TopDownMerge(ref b, begin, middle, end, ref a);
        }
        private static void TopDownMerge(ref int[] a, int begin, int middle, int end, ref int[] b)
        {
            int i = begin, j = middle;
            for (int k = begin; k < end; k++)
            {
                if (i < middle && (j >= end || a[i] <= a[j]))
                {
                    b[k] = a[i];
                    i += 1;
                }
                else
                {
                    b[k] = a[i];
                    j += 1;
                }
            }
        }
        public static void MaxHeapify(ref int[] resource, int i)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;
            if (left < resource.Length && resource[left] > resource[largest]) largest = left;
            if (right < resource.Length && resource[right] > resource[largest]) largest = right;
            if (largest != i)
            {
                int temp = resource[i];
                resource[i] = resource[largest];
                resource[largest] = temp;
                MaxHeapify(ref resource, largest);
            }
        }
        public static void MinHeapify(ref int[] resource, int i)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;
            if (left < resource.Length && resource[left] < resource[smallest]) smallest = left;
            if (right < resource.Length && resource[right] < resource[smallest]) smallest = right;
            if (smallest != i)
            {
                int temp = resource[i];
                resource[i] = resource[smallest];
                resource[smallest] = temp;
                MinHeapify(ref resource, smallest);
            }
        }
        public static void BuildMinHeap(ref int[] resource, int i)
        {
            int start = i / 2 - 1;
            for (i = start; i >= 0; i--) MinHeapify(ref resource, i);
        }
        public static void BuildMaxHeap(ref int[] resource, int i)
        {
            int start = i / 2 - 1;
            for (i = start; i >= 0; i--) MaxHeapify(ref resource, i);
        }
    }
}