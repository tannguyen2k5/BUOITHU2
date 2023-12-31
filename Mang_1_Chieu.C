#include <stdlib.h>
#include <stdio.h>

void nhapMang(int** arr, int n) {
    *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &(*arr)[i]);
    }
}

void xuatMang(int* arr, int n) {
    printf("Mang vua nhap la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int timMax(int* arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int tinhTich(int* arr, int n) {
    int tich = 1;
    for (int i = 0; i < n; i++) {
        tich *= arr[i];
    }
    return tich;
}

int laSoNguyenTo(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void demTongSoNguyenTo(int* arr, int n, int* count, int* sum) {
    *count = 0;
    *sum = 0;
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(arr[i])) {
            (*count)++;
            (*sum) += arr[i];
        }
    }
}

void inViTri(int* arr, int n, int x) {
    int found = 0;
    printf("Vi tri cac phan tu co gia tri bang %d la: ", x);
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong co phan tu nao co gia tri bang %d", x);
    }
    printf("\n");
}

void sapXepTangDan(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void chenGiaTri(int** arr, int* n, int x, int viTri) {
    (*n)++;
    *arr = (int*)realloc(*arr, (*n) * sizeof(int));
    for (int i = (*n) - 1; i > viTri; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[viTri] = x;
}

// Hàm xóa giá trị k khỏi mảng
void xoaGiaTri(int** arr, int* n, int k) {
    int count = 0;
    for (int i = 0; i < *n; i++) {
        if ((*arr)[i] == k) {
            count++;
        } else {
            (*arr)[i - count] = (*arr)[i];
        }
    }
    *n -= count;
    *arr = (int*)realloc(*arr, (*n) * sizeof(int));
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int* arr;

    nhapMang(&arr, n);
    xuatMang(arr, n);

    int max = timMax(arr, n);
    printf("Gia tri lon nhat trong mang la: %d\n", max);

    int tich = tinhTich(arr, n);
    printf("Tich cac phan tu trong mang la: %d\n", tich);

    int count, sum;
    demTongSoNguyenTo(arr, n, &count, &sum);
    printf("So phan tu nguyen to trong mang la: %d\n", count);
    printf("Tong cac phan tu nguyen to trong mang la: %d\n", sum);

    int x;
    printf("Nhap gia tri can tim vi tri: ");
    scanf("%d", &x);
    inViTri(arr, n, x);

    sapXepTangDan(arr, n);
    printf("Mang sau khi sap xep tang dan: ");
    xuatMang(arr, n);

    int viTri, giaTri;
    printf("Nhap gia tri can chen: ");
    scanf("%d", &giaTri);
    printf("Nhap vi tri can chen: ");
    scanf("%d", &viTri);
    chenGiaTri(&arr, &n, giaTri, viTri);
    printf("Mang sau khi chen gia tri: ");
    xuatMang(arr, n);

    int k;
    printf("Nhap gia tri can xoa: ");
    scanf("%d", &k);
    xoaGiaTri(&arr, &n, k);
    printf("Mang sau khi xoa gia tri: ");
    xuatMang(arr, n);

    free(arr);

    return 0;
}
