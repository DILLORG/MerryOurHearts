import android.app.Application;
import android.content.res.Configuration;

public class MerryOurHearts extends Application{

    private static MerryOurHearts merryOurHearts;

    //Returns applictaion instance.
    public static MerryOurHearts getInstance(){
        return merryOurHearts;
    }

    @Overide
    public final void onCreate(){
        super.onCreate();
        merryOurHearts = this;
    }
}