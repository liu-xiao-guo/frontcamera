
#include "cameraselector.h"

#include <QMediaService>

void CameraSelector::setCameraObject(QObject *cam)
{
    // get the QCamera from the declarative camera's mediaObject property.
    m_camera = qvariant_cast<QCamera*>(cam->property("mediaObject"));

    // get the video device selector control
    QMediaService *service = m_camera->service();
    m_deviceSelector = qobject_cast<QVideoDeviceSelectorControl*>(service->requestControl(QVideoDeviceSelectorControl_iid));
}


QObject *CameraSelector::cameraObject() const
{
    return m_camera;
}

int CameraSelector::selectedCameraDevice() const
{
     return 0;
}

void CameraSelector::setSelectedCameraDevice(const int cameraId)
{
    // A camera might already be started, make sure it's unloaded
    m_camera->unload();

    m_deviceSelector->setSelectedDevice(cameraId);
}
