package fun.krits.videotest;

import com.aliyuncs.DefaultAcsClient;
import com.aliyuncs.exceptions.ClientException;
import com.aliyuncs.vod.model.v20170321.GetPlayInfoRequest;
import com.aliyuncs.vod.model.v20170321.GetPlayInfoResponse;
import com.aliyuncs.vod.model.v20170321.GetVideoPlayAuthRequest;
import com.aliyuncs.vod.model.v20170321.GetVideoPlayAuthResponse;

import java.util.List;

public class AliyunVideoTest {
    public static void main(String[] args) throws ClientException {
        //1 根据视频id获取视频播放地址
        //创建初始化对象
        DefaultAcsClient client = InitObject.initVodClient("LTAI4GDBRMU2vK3iFyaaz81Z", "V1qQgvPwvhtr32uRDiNnWT2uCftdWk");
        GetPlayInfoResponse response = new GetPlayInfoResponse();
        try {
            response = getPlayInfo(client);
            List<GetPlayInfoResponse.PlayInfo> playInfoList = response.getPlayInfoList();
            //播放地址
            for (GetPlayInfoResponse.PlayInfo playInfo : playInfoList) {
                System.out.print("PlayInfo.PlayURL = " + playInfo.getPlayURL() + "\n");
            }
            //Base信息
            System.out.print("VideoBase.Title = " + response.getVideoBase().getTitle() + "\n");
        } catch (Exception e) {
            System.out.print("ErrorMessage = " + e.getLocalizedMessage());
        }
        System.out.print("RequestId = " + response.getRequestId() + "\n");


        GetVideoPlayAuthResponse response2 = new GetVideoPlayAuthResponse();
        try {
            response2 = getVideoPlayAuth(client);
            //播放凭证
            System.out.print("PlayAuth = " + response2.getPlayAuth() + "\n");
            //VideoMeta信息
            System.out.print("VideoMeta.Title = " + response2.getVideoMeta().getTitle() + "\n");
        } catch (Exception e) {
            System.out.print("ErrorMessage = " + e.getLocalizedMessage());
        }
        System.out.print("RequestId = " + response2.getRequestId() + "\n");
    }

    private static GetVideoPlayAuthResponse getVideoPlayAuth(DefaultAcsClient client) throws ClientException {
        GetVideoPlayAuthRequest request = new GetVideoPlayAuthRequest();
        request.setVideoId("31df2da7ffb34874820d1a91d73edf31");
        return client.getAcsResponse(request);
    }

    private static GetPlayInfoResponse getPlayInfo(DefaultAcsClient client) throws ClientException {
        GetPlayInfoRequest request = new GetPlayInfoRequest();
        request.setVideoId("31df2da7ffb34874820d1a91d73edf31");
        return client.getAcsResponse(request);
    }
}
