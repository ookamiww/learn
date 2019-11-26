package com.smartf;

import org.opencv.core.Core;
import org.opencv.core.Mat;
import org.opencv.core.Scalar;
import org.opencv.core.Size;
import org.opencv.highgui.HighGui;
import org.opencv.imgcodecs.Imgcodecs;
import org.opencv.imgproc.Imgproc;
import org.opencv.videoio.VideoCapture;

import java.io.File;
import java.text.DecimalFormat;
import java.text.Format;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Pattern;

public class MakeSprite {

    static {System.loadLibrary(Core.NATIVE_LIBRARY_NAME);}
    private static int a = 1;

    public static void main(String[] args) {

        List<Mat> matList;
        //输入视频路径
        System.out.println("输入视频路径");
        Scanner videoAdd = new Scanner(System.in);
        String video = videoAdd.next();
        if (video != null && !"".equals(video)){
            File videoFile = new File(video);
            if (!isVideo(videoFile)) {
                System.out.println("不是视频文件");
                System.exit(0);
            }
        }
//        if (video == null || "".equals(video)){
//            System.out.println("路径为空");
//            System.exit(0);
//        }



        //输入雪碧图输出路径
        System.out.println("输入雪碧图输出路径");
        Scanner spriteAdd = new Scanner(System.in);
        String sprite = spriteAdd.next();
        if (sprite != null && !"".equals(sprite)){
            File spriteFile = new File(sprite);
            if (!spriteFile.isDirectory()){
                System.out.println("请输入一个文件夹路径");
                System.exit(0);
            }
        }
//        if (sprite == null || "".equals(sprite)){
//            System.out.println("路径为空");
//            System.exit(0);
//        }

        //判断雪碧图输出路径是否为文件夹


        //输入要做成雪碧图的每行个数
        System.out.println("雪碧图需要的格式(正整数)");
        Scanner num = new Scanner(System.in);
        String count = num.next();
        if (count == null || "".equals(count)){
            System.out.println("输入为空");
            System.exit(0);
        }
        //判断输入的是否为整形数字
        if (!isNum(count)){
            System.out.println("请输入一个大于0的正整数");
            System.exit(0);
        }
        int n = Integer.parseInt(count);

        //读取视频并将每帧Mat缩放0.1倍
        matList = readVideo(video);

        //制作雪碧图
        System.out.println("正在制作雪碧图");
        while (true) {

            int i = makeSprite(matList, n, sprite);
            if (i == 1){
                System.out.println("雪碧图制作完成");
                break;
            }
        }

        System.exit(0);

    }

    /**
     * 判断文件是否为视频文件
     * @param videoFile 文件对象
     * @return 真假
     */
    private static boolean isVideo(File videoFile) {

        String regex = "(mp4|flv|avi|mkv|rmvb|wmv)";
        Pattern p = Pattern.compile(regex);

        return p.matcher(videoFile.getName()).find();
    }

    /**
     * 判断字符串是否为正整数
     * @param count 输入字符串
     * @return 真假
     */
    private static boolean isNum(String count) {

        String regex = "^[1-9]\\d*$";

        return count.matches(regex);
    }

    /**
     * 使用OpenCV读取视频并缩放图片
     * @param video 视频路径
     * @return 返回一个Mat集合
     */
    private static List<Mat> readVideo(String video) {

        VideoCapture vc = new VideoCapture();
        List<Mat> matList = new ArrayList<>();

        vc.open(video);
        if (!vc.isOpened()) {
            System.out.println("打开失败");
            return matList;
        }

        Mat frame = new Mat();

        System.out.println("正在读取");
        while (true) {

            if (!vc.read(frame)) {
                System.out.println("读取完成");
                break;
            }
            HighGui.imshow("video",frame);

            //缩放图片
            Mat resize = resizeMat(frame);

            //添加缩放后的图片到集合中
            matList.add(resize);

            if (HighGui.waitKey(30) == 27){
                System.out.println("停止读取");
                return matList;
            }
        }

        return matList;
    }

    /**
     * 缩放图片至0.1倍
     * @param frame 原图片
     * @return 缩放后图片
     */
    private static Mat resizeMat(Mat frame) {
        Mat dst = frame.clone();

        //获取原图片的宽高
        double width = frame.width();
        double height = frame.height();

        //缩放图片至0.1倍
        Imgproc.resize(frame,dst,new Size(width * 0.1,height * 0.1));

        return dst;
    }

    private static int makeSprite(List<Mat> matList, int n, String sprite) {

        List<Mat> hList = new ArrayList<>();
        List<Mat> vList = new ArrayList<>();

        Mat[] h = new Mat[n];
        Mat[] v = new Mat[n];

        Mat spritePic = new Mat();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matList.size() > 0 ){
                    h[j] = matList.get(0);
                    matList.remove(0);
                    hList.add(h[j]);
                }else {
                    if (h[0] != null) {
                        Mat mat = new Mat(h[0].rows(), h[0].cols(), h[0].type(), new Scalar(0));
                        hList.add(mat);
                    }else {
                        return 1;
                    }
                }
            }
            v[i]  = new Mat();
            Core.hconcat(hList,v[i]);
            hList.clear();
            vList.add(v[i]);
            Core.vconcat(vList,spritePic);
        }
        Format form = new DecimalFormat("000");

        System.out.println("第"+a+"张雪碧图已完成,文件名:"+form.format(a)+".jpg");
        Imgcodecs.imwrite(sprite+form.format(a)+".jpg",spritePic);
        a++;

        return 0;
    }

}
