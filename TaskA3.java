import org.apache.poi.ss.usermodel.*;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import java.io.FileInputStream;
import java.io.IOException;

public class ExcelReader {
    public static void main(String[] args) {
        String excelFilePath = "data.xlsx"; 
        
        try (FileInputStream fis = new FileInputStream(excelFilePath);
             Workbook workbook = new XSSFWorkbook(fis)) {

            Sheet sheet = workbook.getSheetAt(0);
            
            for (Row row : sheet) {
                for (Cell cell : row) {
                    printCellValue(cell); 
                }
                System.out.println(); 
            }
        } catch (IOException e) {
            System.err.println("Error reading Excel file: " + e.getMessage());
        }
    }

    private static void printCellValue(Cell cell) {
        if (cell == null) {
            System.out.print("Empty Cell\t");
            return;
        }

        switch (cell.getCellType()) {
            case STRING:
                System.out.print(cell.getStringCellValue() + "\t");
                break;
            case NUMERIC:
                System.out.print(cell.getNumericCellValue() + "\t");
                break;
            case BOOLEAN:
                System.out.print(cell.getBooleanCellValue() + "\t");
                break;
            default:
                System.out.print("Unknown Cell Type\t");
        }
    }
}
